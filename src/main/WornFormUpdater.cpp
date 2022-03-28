#include "WornFormUpdater.h"

auto WornFormUpdater::GetSingleton() -> WornFormUpdater*
{
	static WornFormUpdater singleton{};
	return std::addressof(singleton);
}

void WornFormUpdater::Install()
{
	auto eventSource = RE::ScriptEventSourceHolder::GetSingleton();
	eventSource->AddEventSink<RE::TESActorLocationChangeEvent>(GetSingleton());
	eventSource->AddEventSink<RE::TESCombatEvent>(GetSingleton());
	eventSource->AddEventSink<RE::TESMagicEffectApplyEvent>(GetSingleton());
}

auto WornFormUpdater::ProcessEvent(
	const RE::TESActorLocationChangeEvent* a_event,
	[[maybe_unused]] RE::BSTEventSource<RE::TESActorLocationChangeEvent>* a_eventSource)
	-> RE::BSEventNotifyControl
{
	auto& actor = a_event->actor;
	if (actor && actor->Is3DLoaded()) {
		Ext::Actor::Update3D(actor);
	}

	return RE::BSEventNotifyControl::kContinue;
}

auto WornFormUpdater::ProcessEvent(
	const RE::TESCombatEvent* a_event,
	[[maybe_unused]] RE::BSTEventSource<RE::TESCombatEvent>* a_eventSource)
	-> RE::BSEventNotifyControl
{
	auto actor = a_event->actor.get()->As<RE::Actor>();
	if (actor && actor->Is3DLoaded()) {
		Ext::Actor::Update3D(actor);
	}

	return RE::BSEventNotifyControl::kContinue;
}

auto WornFormUpdater::ProcessEvent(
	const RE::TESMagicEffectApplyEvent* a_event,
	[[maybe_unused]] RE::BSTEventSource<RE::TESMagicEffectApplyEvent>* a_eventSource)
	-> RE::BSEventNotifyControl
{
	auto target = a_event->target.get()->As<RE::Actor>();
	if (target && target->Is3DLoaded()) {
		Ext::Actor::Update3D(target);
	}

	return RE::BSEventNotifyControl::kContinue;
}
