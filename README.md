[![Build Status](https://travis-ci.org/ORNL-QCI/xacc-dwave.svg?branch=master)](https://travis-ci.org/ORNL-QCI/xacc-dwave)

# XACC Plugins for working with D-Wave Quantum Annealer
These plugins for XACC provide a Compiler implementation for D-Wave QMI and an Accelerator implementation targeting the remote D-Wave QPU infrastructure

Installation
------------
With the XACC framework installed run the following
```bash
$ git clone --recursive https://github.com/ornl-qci/xacc-dwave
$ cd xacc-dwave && mkdir build && cd build
$ cmake .. -DXACC_DIR=$HOME/.xacc (or wherever you installed XACC)
$ make install 
```

Documentation
-------------

* [XACC Website and Documentation ](https://xacc.readthedocs.io)

Questions, Bug Reporting, and Issue Tracking
--------------------------------------------

Questions, bug reporting and issue tracking are provided by GitHub. Please
report all bugs by creating a new issue with the bug tag. You can ask
questions by creating a new issue with the question tag.

License
-------

XACC-DWave is licensed - [BSD 3-Clause](LICENSE).
