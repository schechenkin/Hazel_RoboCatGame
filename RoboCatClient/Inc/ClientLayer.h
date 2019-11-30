#pragma once
#include "Hazel.h"

class ClientLayer : public Hazel::Layer
{
public:
	ClientLayer(string& destination, string& name);
	virtual ~ClientLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Hazel::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Hazel::Event& e) override;
private:
};