#pragma once

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <shellapi.h>  // For CommandLineToArgvW
#include <wrl.h>    // For Microsoft::WRL::ComPtr

// DirectX 12 specific headers.
#include "d3dx12.h"
#include <DirectXMath.h>
#include <d3dcompiler.h>
#include <dxgi1_6.h>
#include <dxgidebug.h>  // For ReportLiveObjects.

// STL Headers
#include <algorithm>
#include <atomic>
#include <cassert>
#include <chrono>
#include <condition_variable>
#include <filesystem>
#include <functional>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <sstream>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

// Assimp header files.
#include <assimp/Exporter.hpp>
#include <assimp/Importer.hpp>
#include <assimp/ProgressHandler.hpp>
#include <assimp/anim.h>
#include <assimp/mesh.h>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

// Math header files.
#include "VectorMath.h"
#include "Common.h"

// My head files
// #include "d3dUtil.h"
#include "Helpers.h"

// The min/max macros conflict with like-named member functions.
// Only use std::min and std::max defined in <algorithm>.
#if defined(min)
#undef min
#endif

#if defined(max)
#undef max
#endif

//// In order to define a function called CreateWindow, the Windows macro needs to
//// be undefined.
//#if defined(CreateWindow)
//#undef CreateWindow
//#endif

// using name
using namespace Microsoft::WRL;