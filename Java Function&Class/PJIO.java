import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
BufferedReader keyin=new BufferedReader(new InputStreamReader(System.in));
static String readln(int maxLg){
	byte lin[]=new byte[maxLg];
	int lg=0,car=-1;

	try{
		while(lg<maxLg){
			car=System.in.read();
			if((car<0) || (car=='\n')) 
				break;
            		lin[lg++]+=car;
        	}
        }catch(IOException e){
            return(null);
	}

	if((car<0) && (lg==0)) 
		return (null);
	return (new String(lin,0,lg));
}	