cd ~/CP;
files=(*);
mv ${files[0]} ~/Algorithms/localCppRepo;


cd ~/Algorithms/localCppRepo;

$we=ls;
for i in "$we"
do 
    git add .;
    git commit -m"added";
    git push origin master;
done