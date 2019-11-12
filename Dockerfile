FROM centos:8

RUN dnf -y update && \
    dnf -y install gcc make httpd httpd-devel pkgconfig libcap-devel redhat-rpm-config && \
    dnf clean all && \
    rm -rf /var/cache/dnf

RUN pushd /root && \
    curl -o v1.1.4.tar.gz -LO https://github.com/matsumotory/mod_process_security/archive/v1.1.4.tar.gz && \
    tar zxf v1.1.4.tar.gz && \
    pushd mod_process_security-1.1.4 && \
    make && \
    make install && \
    popd && \
    rm -rf v1.1.4.tar.gz mod_process_security-1.1.4 && \
    popd

EXPOSE 80

CMD ["/usr/sbin/httpd", "-D", "FOREGROUND"]
