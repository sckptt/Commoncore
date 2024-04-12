#!/bin/bash

# Architecture shows here:
arch=$(uname -a)

# Number of physical processors shows here:
cpuph=$(grep "physical id" /proc/cpuinfo | wc -l)

# Number of virtual processors shows here:
vcpu=$(grep processor /proc/cpuinfo | wc -l)

# RAM usage info shows here:
memus=$(free -m | awk '$1 == "Mem:" {printf "%s/%sMb (%.2f%%)\n", $3, $2, $3/$2*100}')

# Disk memory usage info shows here:
diskus=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{memory_used += $3} {memory_total += $2} END {printf "%s/%.0fGb (%.d%%)\n", memory_used, memory_total/1024, memory_used/memory_total*100}')

# CPU load shows here:
cpul=$(top -bn1 | grep -A 1 PID | tail -n 1 | awk '{print $9}')

# Last reboot info shows here:
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')

# LVM use info shows here:
lvmus=$(lsblk | grep lvm | awk '{if ($1) {print "yes"; exit;} else {print "no"}}')

# The number of TCP connections shows here:
ctcp=$(ss -ta | grep ESTAB | wc -l)

# The number of users using the server shows here:
uslog=$(users | wc -l)

# The IPv4 address of your server and its 
# MAC (Media Access Control) address shows here:
ip=$(hostname -I)
nw=$(ip link | grep "link/ether" | awk '{print $2}')

# The number of commands executed with 
# the sudo program shows here:
exsudo=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall " #Architecture: $arch
#CPU physical: $cpuph
#vCPU: $vcpu
#Memory Usage: $memus
#Disk Usage: $diskus
#CPU load: $cpul%
#Last boot: $lb
#LVM use: $lvmus
#Connections TCP: $ctcp ESTABLISED
#User log: $uslog
#Network: IP $ip ($nw)
#Sudo: $exsudo cmd"
