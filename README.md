## Hashmap-Array: Storing large integers with lookup in O(1), and sorting in O(1) 
This project takes a file of 6-8 digit integers, unsorted, and stores them in an array of key-value
pairs where each key has a value of 10*key. We implement a hash-map with chaining to store the keys and values.
However, since values might get very large, we save memory resources by only storing a key and a corrosponding
index in the hash-map. We also implement a radix-sort that sorts the array of key-value pairs by key and outputs
a file of sorted keys in the same format as the input file. The hash-map supports the insert and look-up, and delete
opertions, and also a monitor function that calculates the number of empty locations in the hash-map, and the 
longest chain.

## Installation:
First you need to clone or download the project.

![sc2](https://user-images.githubusercontent.com/73697128/202071025-59a22098-512d-4b55-ab96-a97787ebf66f.jpg)

Before running the project you need to set the directory of the target text file, which is set by default to "C:\\Users\\Wafik\\Downloads\\keys.txt".
```c++
const string filePath = "[your file path]";
```
## Note:
The target text file should have a similar structure to "keys.txt" and "output.txt", which looks something like this:
```txt
14425
14394
11510
10940
25680
28136
28361
25656
10144
28880
.
.
.
```
Now you can run the project and it should run succesfully.
## Usage:
When you compile the project the main menu will appear

![screenshot1](https://user-images.githubusercontent.com/73697128/202068215-7f3121a2-6401-4020-a65c-36a6b8009adc.jpg)

Pressing 1, the program will output all of the key-value pairs in the file (10 on each line):

```bash
{14336 , 143360}{10327 , 103270}{24907 , 249070}{16884 , 168840}{20595 , 205950}{25105 , 251050}{10503 , 105030}{25076 , 250760}{15681 , 156810}{29143 , 291430}
{18314 , 183140}{25710 , 257100}{16005 , 160050}{15269 , 152690}{10740 , 107400}{12454 , 124540}{16855 , 168550}{20365 , 203650}{23226 , 232260}{27938 , 279380}
{23210 , 232100}{20387 , 203870}{13861 , 138610}{21568 , 215680}{28338 , 283380}{21516 , 215160}{10915 , 109150}{12293 , 122930}{22401 , 224010}{17089 , 170890}
{28040 , 280400}{20966 , 209660}{25224 , 252240}{16066 , 160660}{11221 , 112210}{29003 , 290030}{29949 , 299490}{15076 , 150760}{17764 , 177640}{16494 , 164940}
{24824 , 248240}{19548 , 195480}{18703 , 187030}{20964 , 209640}{14531 , 145310}{17460 , 174600}{25635 , 256350}{12353 , 123530}{26141 , 261410}{21351 , 213510}
{20275 , 202750}{15979 , 159790}{16442 , 164420}{18732 , 187320}{21518 , 215180}{10567 , 105670}{24924 , 249240}{25030 , 250300}{14555 , 145550}{10789 , 107890}
{17676 , 176760}{28894 , 288940}{19745 , 197450}{28497 , 284970}{15814 , 158140}{24575 , 245750}{20357 , 203570}{22882 , 228820}{16688 , 166880}{16117 , 161170}
{11334 , 113340}{23262 , 232620}{18934 , 189340}{29778 , 297780}{17692 , 176920}{10986 , 109860}{24433 , 244330}{18320 , 183200}{20891 , 208910}{24733 , 247330}
.
.
.
.
```
Pressing 2- sorts the key-value pairs in ascending order by key, and outputs the pairs in the console, and in an output file in the same directory as the project file
"output.txt".

![sc3](https://user-images.githubusercontent.com/73697128/202071337-45f76c35-0c8d-4589-a561-ca7a6d5d5b12.jpg)

Pressing 3- let's you search the the integers of the file, and outputs the key's location in the hashmap, and it's index in the array.

![sc4](https://user-images.githubusercontent.com/73697128/202071689-42d490bb-01e1-42ce-8779-94136a68ba7d.jpg)

Pressing 4- outputs a string that replicates the structure of the hashmap for visualization purposes. The output is in the format
[Bucket Number] --> {key, index} --> {key, index} --> ...

```txt
[0]--> {key= 18000, index in keyValuePair arr= 638}--> {key= 24000, index in keyValuePair arr= 3170}
[1]--> {key= 12001, index in keyValuePair arr= 2390}--> {key= 18001, index in keyValuePair arr= 3269}
[2]
[3]
[4]
[5]--> {key= 24005, index in keyValuePair arr= 3982}--> {key= 18005, index in keyValuePair arr= 5926}
[6]
[7]--> {key= 12007, index in keyValuePair arr= 2456}
[8]--> {key= 18008, index in keyValuePair arr= 1340}--> {key= 12008, index in keyValuePair arr= 5172}
[9]
[10]--> {key= 24010, index in keyValuePair arr= 3096}--> {key= 18010, index in keyValuePair arr= 5397}
[11]--> {key= 12011, index in keyValuePair arr= 1459}--> {key= 24011, index in keyValuePair arr= 5730}
[12]--> {key= 24012, index in keyValuePair arr= 3788}--> {key= 12012, index in keyValuePair arr= 4955}
.
.
.
.
```
Pressing 5- output a string that checks the longest chain in the hashmap, and the percentage of non-empty locations. The output looks something like this:
```txt
----------------------------------------------------------------------
bucket with the max chain is at index 4403 and has 4 elements         |
69% of locations have 1 or more elements                              |
----------------------------------------------------------------------
```



