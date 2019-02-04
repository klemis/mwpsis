# Instrukcja

###### Zbudować Makefile w projekcie:
./Makefile

================================

sudo apt-get install apache2
sudo apt-get install curl
cd /etc/apache2/mods-enabled
sudo ln -s ../mods-available/cgi.load
sudo service apache2 reload

================================

###### Pobrać cgicc-3.2.15.tar.gz
wget ftp://ftp.gnu.org/gnu/cgicc/cgicc-3.2.15.tar.gz
tar xzf cgicc-3.2.15.tar.gz
cd cgicc-3.2.15.tar.gz
./configure --prefix=/usr
sudo make install

================================

###### Skopiować plik do /var/www
sudo cp cgi.html /var/www/html/cgi.html
chmod o+w MwPSiS

================================

g++ -o cgi cgi.cpp /usr/lib/libcgicc.a
sudo cp cgi /usr/lib/cgi-bin

================================

###### Strona pod adresem
http://localhost/cgi.html