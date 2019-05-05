a program that simulates two operating system scheduling algorithms:
First Come First Served (FCFS) and Round Robin (RR).the program reads an input file that lists the information of the processes that need to be scheduled to run on the processor.
the program simulates scheduling these processes using one of the two algorithms and output the state of each process at every cycle time.
also the program maintain statistics about the processes and output them after the simulation finishes.

Each line in the input file contains four numbers interpreted as follows :
- Process ID
- CPU time : this is the time the process needs to execute on the CPU to complete.It is
represented as a number of simulation cycles.
- I/O time : his is the time the process will need to wait for I/O. Note that this is the
number of simulation cycles a process will remain blocked, and you can safely
assume that processes do not compete for the I/O devices.
- Arrival time:this is the time the process becomes available in the system.It is
represented as simulation time cycle.

A process arriving at the system will run as follows. It will need to run for CPU time, block
for I/O time, and then run for CPU time again.

the program then outputs all the simulation info into a text file named ouputFCFS.txt or outputRR.txt the output file
will be formatted to output two parts.

1)The simulation of the scheduling starting from simulation time cycle 0. Every line shows the
following:
- Simulation cycle time.
- The state of each process: Running, Ready, or Blocked. This should appear as
follows: K: STATE to represent the state of process with ID K. Therefore, for a
running process 1,you should present it as 1: Running.
- Note that at simulation listing, you should not type process that have terminated or
that have not arrived yet.

2)Statistics collected about the simulation. You need to print the following:
- Finishing time. This is the last simulation time at which all the processes have
terminated.
- CPU utilization. This can be calculated as the ratio between the number of the
simulation
- cycles at which the CPU was busy divided by the total number of the simulation
cycles.
- For each process, print the turnaround time. This is calculated as: (the cycle the
process finished - the cycle the process arrived +1).

the output of the provided example in proccess.txt file should look like this for and FCFS algorithm

0 0: running

1 0: blocked

2 0: blocked

3 0: running 2: ready

4 2: running

5 1: running 2: blocked

6 1: blocked 2: running

7 1: running

Finishing time: 7

CPU Utilization: 0.75

Turnaround time of Process 0: 4

Turnaround time of Process 1: 3

Turnaround time of Process 2: 4

the program simulates the following two scheduling algorithms.

First Come First Serve (FCFS):

- When a new process arrives to the system (read from input file), it is added
to the end of the queue.
- Processes that finish their I/O blocking time are added to the end of the queue.
- If two processes are ready at the same time, the one with the lowest ID is chosen to
run.
- If two processes arrive at the same time, then the process with the lowest ID is added
to the ready queue first.

Round Robin (RR):

- The scheduler selects a new process to run on the CPU in the following cases:
a. The process currently running on the CPU finishes its CPU time and it will
terminate.
b. The process currently running on the CPU finishes its CPU time and it will
block for I/O.
c. The process currently running on the CPU has not finished its CPU time.
However, it has spend number of cycles on the CPU equal to the quantum
time.

- When a process is preempted before it finishes its CPU time, it is added to the end of the queue.
- If two processes are ready at the same time, the one with the lowest ID is chosen to
run.
- If two processes arrivat the same time, then the process with the lowest ID is added to
the ready queue first.
