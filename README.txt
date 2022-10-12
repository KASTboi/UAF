(compile vunrable menu)
gcc -g -z execstack -fno-stack-protector -no-pie -m32 -o VunrableMenu VunrableMenu.c

(to get add of get flag function)
objdump -d ./vuln2 | grep getFlag   

place the address into the python program    

(to run exploit)
python3 UAFexploit.py 

(compile patched program)
gcc -g -z execstack -fno-stack-protector -no-pie -m32 -o PATCHED_VunrableMenu PATCHED_VunrableMenu.c

