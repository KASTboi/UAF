(compile vunrable menu)
gcc -g -z execstack -fno-stack-protector -no-pie -m32 -o VulnerableMenu VulnerableMenu.c

(to get add of get flag function)
objdump -d ./VulnerableMenu | grep getFlag   

place the address into the python program    

(to run exploit)
python3 UAFexploit.py 

(compile patched program)
gcc -g -z execstack -fno-stack-protector -no-pie -m32 -o PATCHED_VulnerableMenu PATCHED_VulnerableMenu.c

