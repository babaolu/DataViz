FROM ubuntu:latest

SHELL ["/bin/bash", "-c"]

RUN <<EOF
apt-get update
apt-get upgrade -y
apt-get install -y build-essential openjdk-21-jdk-headless tar wget curl

# Setting up apache tomcat server
wget -c https://dlcdn.apache.org/tomcat/tomcat-10/v10.1.23/bin/apache-tomcat-10.1.23.tar.gz
mkdir -p /opt/tomcat
tar xf apache-tomcat-10.1.23.tar.gz -C /opt/tomcat
ln -s /opt/tomcat/apache-tomcat-10.1.23 /opt/tomcat/updated
chmod +x /opt/tomcat/updated/bin/*.sh

# installs NVM (Node Version Manager)
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.7/install.sh | bash

source $HOME/.nvm/nvm.sh

# download and install Node.js
nvm install 20

# verifies the right Node.js version is in the environment
node -v # should print `v20.13.1`

# verifies the right NPM version is in the environment
npm -v # should print `10.5.2`

EOF

COPY . /DataViz/

WORKDIR /DataViz/spring_back
RUN <<EOF
export JAVA_HOME=$(dirname $(dirname $(readlink -f $(which java))))
./gradlew myjni:build
./gradlew data_generator:build
mv setenv.sh /opt/tomcat/updated/bin/
cp data_generator/build/libs/backspring.war /opt/tomcat/updated/webapps/
EOF

ENV NEXT_PUBLIC_DATAVIZ_URL=web-02.itunz.tech

WORKDIR /DataViz/next_front
RUN <<EOF
source $HOME/.nvm/nvm.sh
npm install next@latest react@latest react-dom@latest -y
npm install @observablehq/plot -y
npm run build
npm i sharp
EOF

EXPOSE 8080/tcp 80/tcp 3000/tcp

ENTRYPOINT ["/bin/bash", "-c", "source /DataViz/startup.sh"]
