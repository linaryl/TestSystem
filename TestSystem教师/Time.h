

class Time
{
public:
	Time();
	~Time();
	void Start(CString);
	void Finish();
private:
	int hour;
	int minute;
	int second;
};