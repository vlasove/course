
import fnmatch
import sys
import os
import json
import matplotlib.pyplot as plt
import pandas as pd

from pylab import rcParams
rcParams['figure.figsize'] = 14, 10


ignore_name = "vlasov.evgeny"
pathname = os.path.dirname(sys.argv[0])


configfiles = [os.path.join(dirpath, f)
               for dirpath, dirnames, files in os.walk(os.path.abspath(pathname))
               for f in fnmatch.filter(files, '*.json')]


unique = {}
for filePath in configfiles:
    with open(filePath, "r") as read_file:
        data = json.load(read_file)
        # print(data)
        for foll in data:
            if foll not in unique.keys():
                unique[foll] = 1
            else:
                unique[foll] += 1

sorted_list = []
for key, val in unique.items():
    sorted_list.append((val, key))

sorted_list.sort(reverse = True)

JsOut = json.dumps(sorted_list)

with open("Output_file.json", "w") as write_file:
    json.dump(unique, write_file)



counter = []
followers_name = []
for pair in sorted_list:
    counter.append(pair[0])
    followers_name.append(pair[1])

dict_for_df = {"counter":counter, "followers_name":followers_name}

df = pd.DataFrame({"counter":counter, "followers_name":followers_name})

ax = df[:15].plot.bar(x='followers_name', y='counter', rot=25)
plt.title("valsov.evgeny's followers following top-15")
plt.savefig("kekekekes.png")
plt.show()

