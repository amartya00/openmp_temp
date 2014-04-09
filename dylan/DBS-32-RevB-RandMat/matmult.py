import dylanbench
import numpy as np

Prof = dylanbench.Profiler(things_to_time=['RunF32', 'RunI32'],
                           time_units='seconds')

Args = []
Ticks = []

print "There will be", len(Args), "runs."

# this needs to get random samples in the range of 1 - 512 (maxValue)
# not sure why this wouldn't work
# could guarantee the number of samples taken
for i in range(100):
    M = int(np.random.rand()*512) + 1
    N = int(np.random.rand()*512) + 1
    P = int(np.random.rand()*512) + 1  
    Args.append([str(M), str(N)])
    Ticks.append(str(M) + ", " + str(N))  
print Args
    
"""
a = 0
c = 0
d = 0
b=1

for j in range(10):
    b=1
    c = int(abs(np.random.randn()*5))
    d += c
    for i in range(10):
        a = int(abs(np.random.randn()*5))
        b = a + b
        print b, d    
        Args.append([str(b), str(d)])
        Ticks.append(str(b) + ", " + str(d))
print Args
print Ticks
"""
"""
Prof.run("MM-Naive", "Benchmarks/MM-Naive/mm_naive", Args, Ticks, n=1)
Prof.run("MM-OneThread", "Benchmarks/MM-OneThread/mm_onethread", Args, Ticks, n=1)
Prof.run("MM-OpenMP", "Benchmarks/MM-OMP/mm_omp", Args, Ticks, n=1)

Prof.saveToFile("Savefiles/MM.bmark")
FILE = Prof.openFile("Savefiles/MM.bmark")

Prof.exportToCSV(FILE, "MM-OpenMP", "Savefiles/CSVs/mm-omp.csv")
Prof.exportToCSV(FILE, "MM-OneThread", "Savefiles/CSVs/mm-onethread.csv")
Prof.exportToCSV(FILE, "MM-Naive", "Savefiles/CSVs/mm-naive.csv")

"""
