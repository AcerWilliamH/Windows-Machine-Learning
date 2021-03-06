#pragma once
#include "Common.h"

class CommandLineArgs
{
public:
    CommandLineArgs() {};
    CommandLineArgs(const std::vector<std::wstring>& args);
    void PrintUsage();
    bool IsUsingGPUHighPerformance() const { return m_useGPUHighPerformance; }
    bool IsUsingGPUMinPower() const { return m_useGPUMinPower; }
    bool UseBGR() const { return m_useBGR; }
    bool IsUsingGPUBoundInput() const { return m_useGPUBoundInput; }
    bool IsIgnoreFirstRun() const { return m_ignoreFirstRun; }
    bool IsPerformanceCapture() const { return m_perfCapture; }
    bool IsDebugOutputEnabled() const { return m_debug; }
    bool TerseOutput() const { return m_terseOutput; }
    bool IsPerIterationCapture() const { return m_perIterCapture; }
    bool IsCreateDeviceOnClient() const { return m_createDeviceOnClient; }
    bool IsAutoScale() const { return m_autoScale; }
    bool IsOutputPerf() const { return m_perfOutput; }


    BitmapInterpolationMode AutoScaleInterpMode() const { return m_autoScaleInterpMode; }
   
    const std::wstring& ImagePath() const { return m_imagePath; }
    const std::wstring& CsvPath() const { return m_csvData; }
    const std::wstring& OutputPath() const { return m_perfOutputPath; }
    const std::wstring& FolderPath() const { return m_modelFolderPath; }
    const std::wstring& ModelPath() const { return m_modelPath; }

    bool UseRGB() const
    {
        // If an image is specified without flags, we load it as a BGR image by default
        return m_useRGB || (!m_imagePath.empty() && !m_useBGR && !m_useTensor);
    }

    bool UseTensor() const
    {
        // Tensor input is the default input if no flag is specified
        return m_useTensor || (!m_useBGR && !UseRGB());
    }

    bool UseGPU() const
    {
        return m_useGPU || (!m_useCPU && !m_useGPUHighPerformance && !m_useGPUMinPower);
    }

    bool UseCPU() const
    {
        // CPU is the default device if no flag is specified
        return m_useCPU || (!m_useGPU && !m_useGPUHighPerformance && !m_useGPUMinPower);
    }

    bool UseCPUBoundInput() const
    {
        // CPU is the default input binding if no flag is specified
        return m_useCPUBoundInput || !m_useGPUBoundInput;
    }

    bool CreateDeviceInWinML() const
    {
        // By Default we create the device in WinML if no flag is specified
        return m_createDeviceInWinML || !m_createDeviceOnClient;
    }

    bool IsGarbageInput() const
    {
        // When there is no image or csv input provided, then garbage input binding is used.
        return m_imagePath.empty() && m_csvData.empty();
    }

    uint32_t NumIterations() const { return m_numIterations; }

    void ToggleCPU(bool useCPU) { m_useCPU = useCPU; }
    void ToggleGPU(bool useGPU) { m_useGPU = useGPU; }
    void ToggleGPUHighPerformance(bool useGPUHighPerformance) { m_useGPUHighPerformance = useGPUHighPerformance; }
    void ToggleUseGPUMinPower(bool useGPUMinPower) { m_useGPUMinPower = useGPUMinPower; }
    void ToggleCreateDeviceOnClient(bool createDeviceOnClient) { m_createDeviceOnClient = createDeviceOnClient; }
    void ToggleCreateDeviceInWinML(bool createDeviceInWinML) { m_createDeviceInWinML = createDeviceInWinML; }
    void ToggleCPUBoundInput(bool useCPUBoundInput) { m_useCPUBoundInput = useCPUBoundInput; }
    void ToggleGPUBoundInput(bool useGPUBoundInput) { m_useGPUBoundInput = useGPUBoundInput; }
    void ToggleUseRGB(bool useRGBImage) {m_useRGB = useRGBImage;}
    void ToggleUseBGR(bool useBGRImage) {m_useBGR = useBGRImage;}
    void ToggleUseTensor(bool useTensor) { m_useTensor = useTensor; }
    void TogglePerformanceCapture(bool perfCapture) { m_perfCapture = perfCapture; }
    void ToggleIgnoreFirstRun(bool ignoreFirstRun) { m_ignoreFirstRun=ignoreFirstRun;}
    void TogglePerIterationPerformanceCapture(bool perIterCapture) { m_perIterCapture = perIterCapture; }
    void ToggleDebugOutput(bool debug) { m_debug = debug; }
    void ToggleTerseOutput(bool terseOutput) { m_terseOutput = terseOutput; }


    void SetModelPath(const std::wstring& modelPath) { m_modelPath = modelPath; }
    void SetInputDataPath(const std::wstring& inputDataPath) { m_inputData = inputDataPath; }
    void SetPerformanceCSVPath(const std::wstring& performanceCSVPath)
    {
        m_perfOutputPath = performanceCSVPath;
        m_perfOutput = true;
    }
    void SetRunIterations(const uint32_t iterations) { m_numIterations = iterations; }
private:
    bool m_perfCapture = false;
    bool m_useCPU = false;
    bool m_useGPU = false;
    bool m_useGPUHighPerformance = false;
    bool m_useGPUMinPower = false;
    bool m_createDeviceOnClient = false;
    bool m_createDeviceInWinML = false;
    bool m_useRGB = false;
    bool m_useBGR = false;
    bool m_useTensor = false;
    bool m_useCPUBoundInput = false;
    bool m_useGPUBoundInput = false;
    bool m_ignoreFirstRun = false;
    bool m_debug = false;
    bool m_perIterCapture = false;
    bool m_terseOutput = false;
    bool m_autoScale = false;
    bool m_perfOutput = false;
    BitmapInterpolationMode m_autoScaleInterpMode = BitmapInterpolationMode::Cubic;

    std::wstring m_modelFolderPath;
    std::wstring m_modelPath;
    std::wstring m_imagePath;
    std::wstring m_csvData;
    std::wstring m_inputData;
    std::wstring m_perfOutputPath;
    uint32_t m_numIterations = 1;
};