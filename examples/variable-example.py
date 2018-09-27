import xacc

xacc.Initialize()

# Get access to D-Wave QPU and 
# allocate some qubits
dwave = xacc.getAccelerator('dwave')
qubits = dwave.createBuffer('q')

# Define the function we'd like to 
# off-load to the QPU, here 
# we're using a the QMI low-level language
@xacc.qpu(accelerator=dwave)
def f(buffer, h, j):
    qmi(0,0,h)
    qmi(1,1,h)
    qmi(0,1,j)

# Execute on D-Wave
f(qubits, 1., 2.)

# Print the buffer, this displays 
# solutions and energies
print(qubits)

xacc.Finalize()