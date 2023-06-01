#遍历网段下所有IP地址
for /L %i IN (1,1,254) DO ping -w 1 -n 1 192.168.1.%i
#查看结果
arp -a
