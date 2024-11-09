#include "Renderer.h"

int main()
{
	GWindow win;
	GEventResponder msgs;
	GVulkanSurface vulkan;
	//int width, height, component;
	//stbi_load("Images/m25.jpg", &width, &height, &component, STBI_rgb_alpha);

	if (+win.Create(0, 0, 800, 600, GWindowStyle::WINDOWEDBORDERED))
	{
		win.SetWindowName("Owi | Bye Week 2024");

		VkClearValue clrAndDepth[2];
		clrAndDepth[0].color = { {0, 0, 0, 1} }; // start with black
		clrAndDepth[1].depthStencil = { 1.0f, 0u };
		msgs.Create([&](const GW::GEvent& e) {
			GW::SYSTEM::GWindow::Events q;
			if (+e.Read(q) && q == GWindow::Events::RESIZE)
				clrAndDepth[0].color.float32[2] += 0.01f; // move towards a yellow as they resize
			});
		win.Register(msgs);
#ifndef NDEBUG
		const char* debugLayers[] = {
			"VK_LAYER_KHRONOS_validation", // standard validation layer
			//"VK_LAYER_RENDERDOC_Capture" // add this if you have installed RenderDoc
		};
		if (+vulkan.Create(win, 0, sizeof(debugLayers) / sizeof(debugLayers[0]), debugLayers, 0, nullptr, 0, nullptr, false))
#else
		if (+vulkan.Create(win, 0))
#endif
		{
			Renderer renderer(win, vulkan);
			while (+win.ProcessWindowEvents())
			{
				if (+vulkan.StartFrame(2, clrAndDepth))
				{
					renderer.Render();
					vulkan.EndFrame(true);
					//break;
				}
			}
		}
	}
	return 0; // that's all folks

}