import dylanbench

Prof = dylanbench.Profiler(things_to_time=['RunF64','RunF32','RunI64','RunI32'],
                           time_units='seconds')

Args = [[str(2**i)] for i in range(2, 19)]
Ticks = [2**i for i in range(2, 19)]

Prof.run("DOT-Naive", "Benchmarks/DOT-Naive/dot_naive", Args, Ticks, n=1)
Prof.run("DOT-OneThread", "Benchmarks/DOT-OneThread/dot_onethread", Args, Ticks, n=1)

Prof.saveToFile("Savefiles/DOT.bmark")
FILE = Prof.openFile("Savefiles/DOT.bmark")

Prof.exportToCSV(FILE, "DOT-Naive", "Savefiles/CSVs/dot-naive.csv")
Prof.exportToCSV(FILE, "DOT-OneThread", "Savefiles/CSVs/dot-onethread.csv")
