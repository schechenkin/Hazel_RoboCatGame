class Client : public Engine
{
public:

	static bool StaticInit(string& destination, string& name);

	virtual void	DoFrame(Hazel::Timestep ts) override;
	virtual void	HandleEvent(Hazel::Event& e) override;

	bool OnKeyPressed(Hazel::KeyPressedEvent& e);
	bool OnKeyReleased(Hazel::KeyReleasedEvent& e);
protected:

	Client(string& destination, string& name);


private:
	Hazel::OrthographicCameraController m_CameraController;


};