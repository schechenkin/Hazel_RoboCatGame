class Server : public Engine
{
public:

	static bool StaticInit(uint16_t port);

	virtual void DoFrame(Hazel::Timestep ts) override;
	virtual int Run();

	void HandleNewClient(ClientProxyPtr inClientProxy);
	void HandleLostClient(ClientProxyPtr inClientProxy);

	RoboCatPtr GetCatForPlayer(int inPlayerId);
	void SpawnCatForPlayer(int inPlayerId);

	void SetupWorld();


private:
	Server(uint16_t port);
	bool InitNetworkManager(uint16_t port);
	uint16_t mPort;
};