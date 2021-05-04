#include <vulkanexamplebase.h>

#include <scene/scene_loader.h>
#include <scene/cacher/buffer_cacher.h>
#include <scene/components/transform.h>
#include <scene/components/camera.h>
#include <scene/components/mesh.h>
#include <scene/components/virtual_texture.h>
#include <scene/geometry/frustum.h>

#include <renderer/culling_pipeline.h>
#include <renderer/scene_pipeline.h>
#include <renderer/hiz_pipeline.h>
#include <renderer/debug_pipeline.h>

#include <vk_mem_alloc.h>

#define HIZ_ENABLE
//#define VIS_HIZ
//#define CPU_FRUSTUM
#define MULTI_THREAD


class Application :public VulkanExampleBase
{
public:
	PFN_vkCmdSetDepthTestEnableEXT vkCmdSetDepthTestEnableEXT;
	VkPhysicalDeviceDescriptorIndexingFeaturesEXT physicalDeviceDescriptorIndexingFeatures{};
	VkPhysicalDeviceDepthClipEnableFeaturesEXT physicalDeviceDepthClipEnableFeatures{};
	VkPhysicalDeviceExtendedDynamicStateFeaturesEXT physicalDeviceExtendedDynamicStateFeatures;
	
public:
	Application();

	~Application();

	void buildCommandBuffers();

	void prepare();

	virtual void getEnabledFeatures() override;

	void draw();

	virtual void render();

	void update();

	virtual void OnUpdateUIOverlay(vks::UIOverlay* overlay) override;

	virtual void updateOverlay() override;

	virtual void windowResized() override;

	void saveScreenShot();

private:
	std::unique_ptr<chaf::Scene> scene{ nullptr };

	std::unique_ptr<CullingPipeline> culling_pipeline;
	std::unique_ptr<ScenePipeline> scene_pipeline;
	std::unique_ptr<HizPipeline> hiz_pipeline;
	std::unique_ptr<DebugPipeline> debug_pipeline;

	int32_t display_debug{ 0 };
};