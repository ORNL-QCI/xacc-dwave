import pyxacc as xacc

src = """__qpu__ variable(AcceleratorBuffer ab, double ta, double tp, double tq, double h, double J) {
    anneal ta tp tq;
    0 0 h;
    1 1 h;
    0 1 J;
}"""

xacc.Initialize(['--compiler','dwave-qmi'])

qpu = xacc.getAccelerator('dwave')
qubits = qpu.createBuffer('qbits')

p = xacc.Program(qpu, src)
p.build()

variable = p.getKernel('variable')

for t in [20.,30.]:
    variable.execute(qubits, [t, 0., 0., 2., 3.])

xacc.Finalize()