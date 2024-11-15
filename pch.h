#define NOMINMAX

// Simple basecode showing how to create a window and attatch a vulkansurface
#define GATEWARE_ENABLE_CORE // All libraries need this
#define GATEWARE_ENABLE_SYSTEM // Graphics libs require system level libraries
#define GATEWARE_ENABLE_GRAPHICS // Enables all Graphics Libraries
#define GATEWARE_ENABLE_INPUT 
#define GATEWARE_ENABLE_MATH
//#define GATEWARE_ENABLE_MMATH2D
// Ignore some GRAPHICS libraries we aren't going to use
#define GATEWARE_DISABLE_GDIRECTX11SURFACE // we have another template for this
#define GATEWARE_DISABLE_GDIRECTX12SURFACE // we have another template for this
#define GATEWARE_DISABLE_GRASTERSURFACE // we have another template for this
#define GATEWARE_DISABLE_GOPENGLSURFACE // we have another template for this
// With what we want & what we don't defined we can include the API
#include "Gateware/Gateware.h"
#include <dxcapi.h>
#include <wrl/client.h>
#pragma comment(lib, "dxcompiler.lib")

#include <random>

using GWindow = GW::SYSTEM::GWindow;
using GWindowStyle = GW::SYSTEM::GWindowStyle;
using GVulkanSurface = GW::GRAPHICS::GVulkanSurface;
using GEventReceiver = GW::CORE::GEventReceiver;
using GEventResponder = GW::CORE::GEventResponder;

using GInput = GW::INPUT::GInput;
using vec4 = GW::MATH::GVECTORF;
using vec3 = GW::MATH2D::GVECTOR3F;
using vec2 = GW::MATH2D::GVECTOR2F;