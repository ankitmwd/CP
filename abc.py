import os
def get_latency(ip):
    response = os.popen(f"ping -c 1 {ip}").read()
    if "time=" in response:
        latency = float(response.split("time=")[-1].split(" ms")[0])
        return latency
    else:
        return float('inf')

if __name__ == "__main__":
    ips = [
        '8.8.8.8',
        '1.1.1.1',
        '208.67.222.222',
    ]
    latencies = [float('inf')] * len(ips)
    for i, ip in enumerate(ips):
        latency = get_latency(ip)
        latencies[i] = latency
    ind = 0
    min_latency = float('inf')
    for i, latency in enumerate(latencies):
        if latency < min_latency:
            min_latency = latency
            ind = i
        print(ips[i],latency)
    if min_latency==float("inf"):
        print("Not Reachable")
    else :
        print("Minimum Latency:", ips[ind], latencies[ind])