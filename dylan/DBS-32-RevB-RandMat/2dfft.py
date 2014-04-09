import dylanbench

Prof = dylanbench.Profiler( things_to_time=['RunF64'], time_units='seconds' )

Args = [[str(2**i)] for i in range(2, 12)]
Ticks = [2**i for i in range(2, 12)]

Prof.run("2DFFT-OneThread", "Benchmarks/2DFFT-OneThread/2dfft_onethread", 
         Args, Ticks, n=1)
Prof.run("2DFFT-OMP", "Benchmarks/2DFFT-OMP/2dfft_omp", 
         Args, Ticks, n=1)

Prof.saveToFile("Savefiles/2DFFT.bmark")
FILE = Prof.openFile("Savefiles/2DFFT.bmark")

Prof.exportToCSV(FILE, "2DFFT-OneThread", "Savefiles/CSVs/2dfft-onethread.csv")
Prof.exportToCSV(FILE, "2DFFT-OMP", "Savefiles/CSVs/2dfft-omp.csv")
