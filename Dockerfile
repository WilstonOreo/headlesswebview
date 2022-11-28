#This is a sample Image 
FROM ubuntu 
MAINTAINER michael@winkelmann.site 
# Time zone info
ENV TZ=Europe/Berlin
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# Install dependencies
RUN apt update
RUN apt install -y g++ qtwebengine5-dev libqt5webengine5 libqt5webenginewidgets5 xvfb
RUN useradd webviewuser
USER webviewuser
WORKDIR /home/webviewuser
CMD ["echo","Image created"]
 
