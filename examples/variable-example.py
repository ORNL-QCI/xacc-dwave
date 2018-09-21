import xacc
xacc.Initialize(['--compiler','dwave-qmi'])

dwave = xacc.getAccelerator('dwave')
qubits = dwave.createBuffer('q')

#xacc.setOption('dwave-solver', 'DW_2000Q_2')
# You can write your kernel like this...
# src = """__qpu__ variable(AcceleratorBuffer ab, double ta, double tp, double tq, double h, double J) {
#    anneal ta tp tq;
#    0 0 h;
#    1 1 h;
#    0 1 J;
# }"""
#
# Then use the Program/Kernel API
#
# p = xacc.Program(qpu, src)
# p.build()
#
# variable = p.getKernel('variable')

# for t in [20.,30.]:
#    variable.execute(qubits, [t, 0., 0., 2., 3.])

# OR without annealing schedule
@xacc.qpu(accelerator=dwave)
def f(buffer, h, j):
    qmi(0,0,h)
    qmi(1,1,h)
    qmi(0,1,j)

# This is how you can 
# set a custom embedding
# qubits.addExtraInfo('embedding', {0:[0],1:[4]})

# Execute on D-Wave
f(qubits, 1., 2.)

print(qubits)



xacc.Finalize()