class TimeServer {
public:
    string GetCurrentTime() {
       try{
  			string now_time = AskTimeServer();
  			LastFetchedTime=now_time;
  			return now_time;
  		}
  		catch (system_error&){
  			return LastFetchedTime;
  		}
    }

private:
    string LastFetchedTime = "00:00:00";
};