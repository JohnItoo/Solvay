##How to setup Your Cron Job on Unix Machines to automate your Git Push

#I use this to push algorithm stuff I solve on the daily. It can be used on some other stuff too.

#CRON

- crontab -l list all cronjobs

- crontab -e . Tap i to move to insert mode in Vim. 

- 30 23 * * * cd ~/Desktop && ./new.sh  >~/log/cron.log
 (Runs at 11:30 pm everyday)

**The last step changes to the the directory to where your bash script lives and spits out in the cron.log file