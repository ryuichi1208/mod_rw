#/bin/bash

sudo dnf -y update && \
sudo dnf -y install gcc make httpd httpd-devel pkgconfig libcap-devel redhat-rpm-config gdb && \
sudo dnf clean all && \
sudo rm -rf /var/cache/dnf
