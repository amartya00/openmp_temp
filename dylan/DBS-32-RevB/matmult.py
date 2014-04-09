import dylanbench

Prof = dylanbench.Profiler(things_to_time=['RunF32', 'RunI32'],
                           time_units='seconds')

MAX = 512
INCR = 16

Args = []
Ticks = []

for i in range(MAX/INCR+1):
    for j in range(1, i+1):
        Args.append([str(i*INCR), str(j*INCR)])
        Ticks.append("M:" + str(i*INCR) + " N:" + str(j*INCR))

print "There will be", len(Args), "runs."

Prof.run("MM-Naive", "Benchmarks/MM-Naive/mm_naive", Args, Ticks, n=1)
Prof.run("MM-OneThread", "Benchmarks/MM-OneThread/mm_onethread", Args, Ticks, n=1)
Prof.run("MM-OpenMP", "Benchmarks/MM-OMP/mm_omp", Args, Ticks, n=1)

Prof.saveToFile("Savefiles/MM.bmark")
FILE = Prof.openFile("Savefiles/MM.bmark")

Prof.exportToCSV(FILE, "MM-OpenMP", "Savefiles/CSVs/mm-omp.csv")
Prof.exportToCSV(FILE, "MM-OneThread", "Savefiles/CSVs/mm-onethread.csv")
Prof.exportToCSV(FILE, "MM-Naive", "Savefiles/CSVs/mm-naive.csv")

