#!/usr/bin/env python3
import pwn, os, psutil, threading
OUT = ''
def monitor_memory(done, pid):
    process = psutil.Process(pid)
    mem_info = process.memory_info()

    peak_mem_usage = 0
    while not done.is_set():
        mem_info = process.memory_info()
        current_mem_usage = mem_info.rss

        if current_mem_usage > peak_mem_usage:
            peak_mem_usage = current_mem_usage

    print(f"| {peak_mem_usage / 1024 / 1024 } |")


CONTAINERS = ['list', 'deque']
files = [1_000, 10_000, 100_000, 1_000_000, 10_000_000]
strategys = ['A', 'B']

for container in CONTAINERS:
    os.system(f'make clean')
    os.system(f'make {container}')
    OUT +=f'| {container} |'
    for strat in strategys:
        OUT +=f'| {strat} |'
        for file in files:
            res = ""
            p = pwn.process('./build/program')

            done = threading.Event()
            memory_thread = threading.Thread(target=monitor_memory, args=(done, p.pid))
            memory_thread.start()

            p.sendlineafter(b'spausk "g"', b'f')
            filename = f'studentai{file}.txt'
            print(file)
            p.sendlineafter(b'ivesk "iseiti":', filename.encode())
            res += p.recvuntil(b'Skaiciuoti galutini pazymi pagal vidurki spausk "v"').decode()
            p.sendlineafter(b'mediana spausk "m"', b'v')
            p.sendlineafter(b'Metodas:', strat.encode()).decode()
            res += p.recvuntil(b'Programos veikimo laikas (Be naudotojo ivesties laukimo laiko):').decode()
            res += p.recvuntil(b's').decode()
            times = [i.split(' ')[-1][:-1] for i in res.strip().split('\n')]
            
            print(f'| {times[2]} |')

            done.set()
            memory_thread.join()