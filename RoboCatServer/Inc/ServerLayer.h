#pragma once

#include "Hazel.h"

class ServerLayer : public Hazel::Layer
{
public:
	ServerLayer(uint16_t port);
	virtual ~ServerLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Hazel::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Hazel::Event& e) override;
private:
};