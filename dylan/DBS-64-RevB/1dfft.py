import dylanbench

Prof = dylanbench.Profiler( things_to_time=['RunF64'], time_units='seconds' )

Args = [[str(2**i)] for i in range(2, 19)]
Ticks = [2**i for i in range(2, 19)]

Prof.run("1DFFT-OneThread", "Benchmarks/1DFFT-OneThread/1dfft_onethread", 
         Args, Ticks, n=1)
Prof.run("1DFFT-OMP", "Benchmarks/1DFFT-OMP/1dfft_omp", 
         Args, Ticks, n=1)

Prof.saveToFile("Savefiles/1DFFT.bmark")
FILE = Prof.openFile("Savefiles/1DFFT.bmark")

Prof.exportToCSV(FILE, "1DFFT-OneThread", "Savefiles/CSVs/1dfft-onethread.csv")
Prof.exportToCSV(FILE, "1DFFT-OMP", "Savefiles/CSVs/1dfft-omp.csv")
