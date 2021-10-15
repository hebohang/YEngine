#pragma once

#include <Windows.h>
#include <shellapi.h>  // For CommandLineToArgvW

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