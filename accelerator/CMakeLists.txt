
find_package(OpenSSL)
find_path(CPPREST_INCLUDE cpprest/http_client.h)
find_library(CPPREST_LIB NAMES cpprest_2_9d cpprest_2_9 cpprestd cpprest)
   
if (OPENSSL_FOUND AND CPPREST_LIB)

   include_directories(${CPPREST_INCLUDE})

   set (PACKAGE_NAME "D-Wave XACC Accelerator")
   set (PACKAGE_DESCIPTION "D-Wave XACC Accelerator Bundle")
   set (LIBRARY_NAME xacc-dwave-accelerator)

   file (GLOB_RECURSE HEADERS *.hpp)
   file (GLOB SRC *.cpp)

   # Set up dependencies to resources to track changes
   usFunctionGetResourceSource(TARGET ${LIBRARY_NAME} OUT SRC)
   # Generate bundle initialization code
   usFunctionGenerateBundleInit(TARGET ${LIBRARY_NAME} OUT SRC)

   add_library(${LIBRARY_NAME} SHARED ${SRC})

   set(_bundle_name xacc_dwave_accelerator)

   set_target_properties(${LIBRARY_NAME} PROPERTIES
     # This is required for every bundle
     COMPILE_DEFINITIONS US_BUNDLE_NAME=${_bundle_name}
     # This is for convenience, used by other CMake functions
     US_BUNDLE_NAME ${_bundle_name}
     )

   if(BUILD_SHARED_LIBS)
     set_target_properties(${LIBRARY_NAME} PROPERTIES
       CXX_VISIBILITY_PRESET hidden
       VISIBILITY_INLINES_HIDDEN 1
      )
   endif()

   # Embed meta-data from a manifest.json file
   usFunctionEmbedResources(TARGET ${LIBRARY_NAME}
     WORKING_DIRECTORY
       ${CMAKE_CURRENT_SOURCE_DIR}
     FILES
       manifest.json
    )

   target_link_libraries(${LIBRARY_NAME} ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES} ${CPPREST_LIB} CppMicroServices xacc xacc-quantum-aqc)

   install(TARGETS ${LIBRARY_NAME} DESTINATION ${XACC_ROOT}/lib/plugins/accelerators)
   
   # Gather tests
   file (GLOB test_files ../tests/DWAcceleratorTester.cpp)
   add_tests("${test_files}" "${CMAKE_CURRENT_SOURCE_DIR}" "xacc-dwave-accelerator;${Boost_LIBRARIES};${XACC_LIBRARIES};dl;pthread")
   
else()
   message(STATUS "OpenSSL or cpprestsdk not found, cannot include D-Wave Accelerator plugin")
endif()
