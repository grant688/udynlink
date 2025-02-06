export PATH=$PATH:/home/master/git/xpack-qemu-arm-7.2.5-1/bin/

python3 test_driver.py $1

find . -name *.o -delete
#find . -name *.txt -delete
find . -name *.elf -delete
find . -name *.bin -delete