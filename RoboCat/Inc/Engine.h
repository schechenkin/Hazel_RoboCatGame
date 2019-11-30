#include <Hazel.h>

class Engine
{
public:

	virtual ~Engine();
	static std::unique_ptr<Engine>	sInstance;

	//virtual int	Run();
	void			SetShouldKeepRunning( bool inShouldKeepRunning ) { mShouldKeepRunning = inShouldKeepRunning; }
	virtual void	HandleEvent(Hazel::Event& e);

protected:
	Engine();
	virtual void	DoFrame(Hazel::Timestep ts);

private:
	//int	DoRunLoop();
	bool mShouldKeepRunning;
};