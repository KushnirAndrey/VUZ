DOMAINS
   RNO,BNO,FNO=integer      
   CONDITIONS=BNO*	          
   HISTORY=RNO*                  
   CATEGORY=symbol
   TEXT=string



DATABASE - mydb
    rule(RNO,CATEGORY,CATEGORY,CONDITIONS)   
    cond(BNO,string)	
  
    yes(BNO)	
    no(BNO)	



PREDICATES
    do_expert_job                                                        
    show_menu    process(integer)                             
    do_consulting                                                        
    goes(CATEGORY)                                              
    go(HISTORY,CATEGORY)                               
    check(RNO,HISTORY,CONDITIONS)             
                                                                                  
    clear	
    notes(BNO)
    inpo(HISTORY,RNO,BNO,string)	
    do_answer(HISTORY,RNO,string,BNO,integer)
    input	
       
      
GOAL
     do_expert_job.


CLAUSES

            do_expert_job:-makewindow(1,7,7,"Types of birds",0,0,25,80),  show_menu, nl,write(">>press space<<"),readchar(_),  exit.




         
              show_menu:-
		write("                                       "),nl,
		write(" ************************************  "),nl,
		write(" *    Types of birds             *  "),nl,
		write(" *                                  *  "),nl,
		write(" *    1. Consultation               *  "),nl,
		write(" *                                  *  "),nl,
		write(" *                                  *  "),nl,
		write(" *    2. Exit the system            *  "),nl,
		write(" *                                  *  "),nl,
		write(" ************************************  "),nl,
		write("                                       "),nl,
		write("Please enter your choice: 1 or 2 : "),nl,
		readint(Choice),
                process(Choice).

            process(1) :-input,	
                 do_consulting. 
            process(2) :-	
                 removewindow,
                 exit.

           
          input:-write("Input DB name <dbname.dba>"),nl,
      		   readln(NF),consult(NF,mydb),
                   write("DB is consulted!"),nl,
                   write("** press space **"),readchar(_).
              

            do_consulting :-goes(Mygoal),go([],Mygoal),!.
            do_consulting :-nl, write("** Sorry I can't help you  **"),clear.
            do_consulting.
            goes(Mygoal) :-clear,clearwindow,nl,nl,
                           write("*********************************************"),nl,
                           write("*                                           *"),nl,     
		           write("*  Definiton of  bird's types           *"),nl,
                  	   write("*                                           *"),nl,
		           write("*                                           *"),nl,
                 	   write("*  To begin the process, please, type 'ok'  *"),nl,
		           write("*                                           *"),nl,
 	                   write("*********************************************"),nl,                                                                                                 readln(Str),nl,Str="ok",Mygoal="type",!.
   
            clear :- retract(yes(_)),retract(no(_)),fail,!.
            clear.
	 
           go(_,Mygoal) :-not(rule(_,Mygoal,_,_)),!,nl,
			   write("*****   Type of birds  is detected - ",Mygoal,".   *****"),nl,!.
            go(HISTORY, Mygoal) :-rule(RNO,Mygoal,NY,COND),
                                  check(RNO,HISTORY,COND),
                                  go([RNO|HISTORY],NY).

            check(RNO,HISTORY,[BNO|REST]) :-yes(BNO),!,check(RNO,HISTORY,REST).
            check(_,_,[BNO|_]) :- no(BNO),!,fail.
            check(RNO,HISTORY,[BNO|REST]) :-cond(BNO,NCOND),
		 			    fronttoken(NCOND,"not",_COND),
 			  		    frontchar(_COND,_,COND),
			                    cond(BNO1,COND),notes(BNO1),!,
            check(RNO,HISTORY,REST).
            check(_,_,[BNO|_]) :-cond(BNO,NCOND),fronttoken(NCOND,"not",_COND),
                 		 frontchar(_COND,_,COND),cond(BNO1,COND),
               			 yes(BNO1),!,fail.
            check(RNO,HISTORY,[BNO|REST]) :-cond(BNO,TEXT),inpo(HISTORY,RNO,BNO,TEXT),
                                            check(RNO,HISTORY,REST).
            check(_,_,[]).

    inpo(HISTORY,RNO,BNO,TEXT) :-write("has  ",TEXT,"? "), 
    makewindow(2,7,7,"Response",13,56,7,20),write("Type 1 for 'yes' ,  "),nl,
    write("Type 2 for 'no' :   "),nl, 	 readint(RESPONSE),  clearwindow,shiftwindow(1),
    do_answer(HISTORY,RNO,TEXT,BNO,RESPONSE).	

            do_answer(_,_,_,_,0) :- exit.
            do_answer(_,_,_,BNO,1) :-assert(yes(BNO),mydb),
		                     shiftwindow(1),write(yes),nl.
            do_answer(_,_,_,BNO,2) :-assert(no(BNO),mydb),write(no),nl,fail.

            notes(BNO):- no(BNO),!.
            notes(BNO):- not(yes(BNO)),!.   
