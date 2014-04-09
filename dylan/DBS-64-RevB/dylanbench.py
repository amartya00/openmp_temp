"""
  A flexible benchmarking tool.

    Copyright (C) 2013  Dylan Rudolph

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
"""

import subprocess
import string
import pickle
import datetime
import platform
import csv

class Profiler():
    
    # Possible time unit options and respective factors
    UNITS = { "nanoseconds": 0.000000001,
              "microseconds": 0.000001,
              "milliseconds": 0.001,
              "seconds": 1.0 }

    # The following dictionary is used to parse through the output of 
    # a function so that the times can be gathered. The program must 
    # output in the proper format. If another time entry is desired, 
    # simply add an entry for it in this dictionary.

    ITEMS = { "runtime": {"start": "RUNTIME: ", "end": ";r"}, 
              "memtime": {"start": "MEMTIME: ", "end": ";m"}, 
              "alloc": {"start": "ALLOCTIME: ", "end": ";a"},
              "dealloc": {"start": "ALLOCTIME: ", "end": ";d"}, 
              "overhead": {"start": "OVERHEADTIME: ", "end": ";o"},
              "other": {"start": "OTHERTIME: ", "end": ";t"},
              "RunF64": {"start": "F64RUNTIME: ", "end": ";rf64"}, 
              "RunF32": {"start": "F32RUNTIME: ", "end": ";rf32"}, 
              "RunI64": {"start": "I64RUNTIME: ", "end": ";ri64"}, 
              "RunI32": {"start": "I32RUNTIME: ", "end": ";ri32"} }

    # The proper formats for each of these is:
    # In C/C++, use printf("RUNTIME: %f;r\n", var); to parse runtime.
    # In C/C++, use printf("ALLOCTIME: %f;a\n", var); to parse alloc.
    # Etc.

    # The following are used for user interface.
    DASH = "-------------------------------------------------------------------"
    HEAD = "----------------- Dylan's Benchmark Manager V0.1 ------------------"
    FOOT = "------------------------------- END -------------------------------"
    CONT = "------------------------ Contents of File  ------------------------"
    META = "---------------------------- Metadata  ----------------------------"
    ALERT = "***"
    LG = "----"
    SM = "--"

    def __init__(self, things_to_time=['runtime'], time_units='seconds'):

        # 'data' is a dictionary which contains everything which is stored:
        # 1) All of the time values
        # 2) All of the x points for those time values
        # 3) Some metadata about the collected information
        self.data = {}

        # 'names' is a list of all of the separate runs which call different 
        # functions.
        self.names = []

        # 'things_to_time' is a user-set list of which data to parse from 
        # the program output
        self.things_to_time = things_to_time

        # time units is one of: 'nanoseconds', ..., 'seconds'
        self.time_units = time_units

        self.tdiv = self.UNITS[self.time_units]

        print "\n", self.DASH
        print self.HEAD
        print self.DASH

    def run(self, name, command, args, ticks, n=1):
        """
        Calls the program 'command' with 'args' as arguments, and puts 'ticks'
        on the x-axis in a plot, with the time on the y-axis. 'n' is the 
        parameter which determines the number of runs to average.
        """
        # Add the name string to the list of names
        self.names.append(name)

        self.cmd = command
        self.args = args
        self.calls = len(args)
        self.call_strings = [' ' for item in range(self.calls)]

        print "\n", self.ALERT, "Preparing for Run", self.ALERT
        print self.ALERT, "Sets of Arguments:", self.calls,self.ALERT
        print self.ALERT, "Name:", name, self.ALERT, "\n"
        
        # Initialize a 'len(self.things_to_time' by 'self.calls' array
        times = [ [0.0 for item in range(len(self.things_to_time))]
                  for j in range(self.calls) ]

        # For each of the function calls
        for i in range(self.calls):

            # Reset the average values
            self.averages = [0.0 for item in range(len(self.things_to_time))]

            # Produce the string which will be put in the command line
            current_args = [self.cmd]
            if self.args[i] not in ['none', ' ']:
                for j in range(len(self.args[i])):
                    current_args.append(self.args[i][j])

            call_string = ''

            for k in range(len(current_args)):
                call_string = call_string + current_args[k]
                if k < len(current_args)-1:
                    call_string = call_string + ' '

            self.call_strings[i] = call_string

            print "Calling: '" + call_string + "' " + repr(n)+ " time(s)."
            
            # For each of the runs to average
            for j in range(n):

                # See what the program gives when called
                return_text = subprocess.check_output(current_args)

                # Parse through the output and check for items in the 
                # 'self.things_to_time' array
                for k in range(len(self.things_to_time)):

                    # 'thing' is might be 'runtime', 'alloc', etc.
                    thing = self.things_to_time[k]

                    # Search for the string specified by the entry for 
                    # 'thing' in the 'ITEMS' dictionary.
                    lower = (return_text.find(self.ITEMS[thing]["start"]) + 
                             len(self.ITEMS[thing]["start"]))

                    upper = return_text.find(self.ITEMS[thing]["end"])

                    # Convert this string to a number and convert it 
                    # to seconds, also normalize for 'n'.
                    self.averages[k] += ((float(return_text[lower:upper]) 
                                          / self.tdiv) / n)

            times[i] = self.averages

            for k in range(len(self.things_to_time)):
                print self.SM, "Average of", self.things_to_time[k], \
                       "was", times[i][k], "seconds"
                                                
        self.data[name] = {"times": times, "ticks": ticks, 
                           "items": self.things_to_time,
                           "call strings": self.call_strings}

    def saveToFile(self, filename='default.benchmark'):
        """ 
        Saves the present benchmark data to a file.
        """
        # Determine todays date.
        today = datetime.date.today()
        year = today.year
        month = today.month
        day = today.day
        
        # Determine system info
        arch = platform.machine()
        os = platform.platform()
        
        # Pack everything into one dictionary
        SAVEDATA = {"data": self.data, "names": self.names, 
                    "year": year, "month": month, "day": day,
                    "arch": arch, "os": os }

        # Write it out to the file
        print "\n", self.ALERT, "Saving to File:", filename, self.ALERT
        fh = open(filename, 'wb')
        pickle.dump(SAVEDATA, fh)
        fh.close()
        print "\n", self.ALERT, "Sucessfully Saved", self.ALERT

    def openFile(self, filename='default.benchmark', print_metadata=True):
        """
        Loads benchmark data which have been saved to a file.
        """
        
        # Open it up and put it in FILE
        fh = open(filename, 'rb')
        FILE = pickle.load(fh)
        fh.close

        # Parse through it
        data = FILE["data"]
        names = FILE["names"]
        year = FILE["year"]
        month = FILE["month"]
        day = FILE["day"]
        arch = FILE["arch"]
        os = FILE["os"]

        # Print out the metadata

        if print_metadata:
            print "\n", self.DASH, "\n", self.HEAD, "\n", self.DASH
            print "\n", self.ALERT, "File Loaded:", filename, self.ALERT, "\n"
            print self.META, "\n"
            print "Run Date (D/M/Y): ", day, "/", month, "/", year
            print "Operating System: ", os
            print "Architecture:     ", arch, "\n"
            print self.CONT
            for i in range(len(names)):
                current_data = FILE["data"][names[i]]
                number_of_entries = len(current_data["times"])
                print "\n", self.SM, names[i]
                print self.LG, "Recorded Data:           ", \
                    FILE["data"][names[i]]["items"]
                print self.LG, "Entries per Item:        ", number_of_entries
                print self.LG, "First Command Line Call: ", \
                    current_data["call strings"][0]
                print self.LG, "Last Command Line Call:  ", \
                    current_data["call strings"][number_of_entries - 1]
            print "\n", self.FOOT, "\n"

        return FILE

    def exportToCSV(self, FILE, name, out_filename):
        """
        Exports one of the runs from a file (identified by 'name') 
        to an excel-friendly csv format.
        """

        data = FILE["data"][name]
        writer =  csv.writer(open(out_filename, 'w'))

        # Make the first row (the headers)
        firstrow = ["Tick"]
        for item in data["items"]:
            firstrow.append(item)
        writer.writerow(firstrow)

        # Make the rest of the rows
        for i in range(len(data["times"])):
            thisrow = [data["ticks"][i]] + data["times"][i]
            writer.writerow(thisrow)
