## For the ARP Poisoning Labs

It is advised that students run the following commands to allow their hosts act as a router and forward the packets they intercept on to their real destinations.

```bash
sudo sysctl net.ipv4.ip_forward=1
sudo echo 0 | sudo tee /proc/sys/net/ipv4/conf/*/send_redirects
sudo iptables -P FORWARD ACCEPT
```

sometimes user will need to flush their iptables to reset and try again. To do so use the command bellow

```bash
sudo iptables -F
```