Shell:
	My bash shell in c implements basic commands,foreground,background processes..
This is a linux shell written in C which implements built in commands like cd,echo etc and system commands like vi..etc. It handles background processes ,redirection,piping and signals also.
  
For Running
	run 'make'
	execute by using './shell'
	run 'quit' to exit
  
FUNCTIONS  
   cd: chanegs the directory  
    ls command :   
    pinfo command:  
    Input/Output redirection:  
    	Ouput of one command can be redirected to a file  
    	Similarly input can be taken from another file  
    Piping:  
    	One or more commands can be piped  
   	 Pipes and i/o redirection can be done together  
    
   setenv var value : used to create environment variable var  
   unsetenv var : shell destroys the environment variable var.  
   jobs :  prints a list of all background processes  
   kjob : takes the job id of a running job and sends a signal value to that process.  
   fg : brings a running or a stopped background job with given job number to foreground.  
   bg : changes a stopped background job to a running background job.  
   overkill : kills all background process at once.  
   CTRL-Z : It changes the status of currently running job to stop, and pushes it in background process.  
   CTRL-C : It should cause a SIGINT signal to be sent to the current foreground job of your shell. If there is no foreground job, then the signal doesn't have any effect.  
    

