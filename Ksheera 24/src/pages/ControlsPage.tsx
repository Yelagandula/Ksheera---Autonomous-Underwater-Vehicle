import React, { useState } from 'react';
import { useSystemStatus } from '../hooks/useSystemStatus';

export default function ControlsPage() {
  const { mode, targetDepth, setMode, setTargetDepth } = useSystemStatus();
  const [commandLog, setCommandLog] = useState<string[]>([]);

  const logCommand = (command: string) => {
    setCommandLog(prev => [...prev, `[${new Date().toLocaleTimeString()}] ${command}`]);
  };

  const handleCommand = (command: string) => {
    logCommand(command);
  };

  return (
    <div className="p-6">
      <h1 className="text-2xl font-bold mb-6">Control Panel</h1>
      
      <div className="grid gap-6">
        <div className="bg-white rounded-lg shadow p-6">
          <h2 className="text-lg font-semibold mb-4">Operation Mode</h2>
          <div className="flex items-center space-x-4">
            <button
              onClick={() => {
                setMode('auto');
                logCommand('Switched to Auto mode');
              }}
              className={`px-4 py-2 rounded-md ${
                mode === 'auto'
                  ? 'bg-blue-600 text-white'
                  : 'bg-gray-100 text-gray-700 hover:bg-gray-200'
              }`}
            >
              Auto
            </button>
            <button
              onClick={() => {
                setMode('manual');
                logCommand('Switched to Manual mode');
              }}
              className={`px-4 py-2 rounded-md ${
                mode === 'manual'
                  ? 'bg-blue-600 text-white'
                  : 'bg-gray-100 text-gray-700 hover:bg-gray-200'
              }`}
            >
              Manual
            </button>
          </div>
        </div>

        <div className="bg-white rounded-lg shadow p-6">
          <h2 className="text-lg font-semibold mb-4">Controls</h2>
          <div className="grid grid-cols-2 gap-4">
            <button
              onClick={() => handleCommand('Dive command initiated')}
              className="bg-blue-600 text-white px-4 py-2 rounded-md hover:bg-blue-700"
            >
              Dive
            </button>
            <button
              onClick={() => handleCommand('Surface command initiated')}
              className="bg-blue-600 text-white px-4 py-2 rounded-md hover:bg-blue-700"
            >
              Surface
            </button>
            <button
              onClick={() => handleCommand('Stop command initiated')}
              className="bg-red-600 text-white px-4 py-2 rounded-md hover:bg-red-700"
            >
              Stop
            </button>
            <button
              onClick={() => handleCommand('Reset command initiated')}
              className="bg-gray-600 text-white px-4 py-2 rounded-md hover:bg-gray-700"
            >
              Reset
            </button>
          </div>
        </div>

        <div className="bg-white rounded-lg shadow p-6">
          <h2 className="text-lg font-semibold mb-4">Target Depth</h2>
          <div className="flex items-center space-x-4">
            <input
              type="number"
              value={targetDepth}
              onChange={(e) => {
                const depth = Number(e.target.value);
                setTargetDepth(depth);
                logCommand(`Target depth set to ${depth}m`);
              }}
              className="px-4 py-2 border border-gray-300 rounded-md w-32"
              min="0"
              max="100"
              step="0.1"
            />
            <span className="text-gray-600">meters</span>
          </div>
        </div>

        <div className="bg-white rounded-lg shadow p-6">
          <h2 className="text-lg font-semibold mb-4">Command Log</h2>
          <div className="bg-gray-50 p-4 rounded-md h-48 overflow-y-auto">
            {commandLog.map((log, index) => (
              <div key={index} className="text-sm text-gray-600 mb-1">
                {log}
              </div>
            ))}
          </div>
        </div>
      </div>
    </div>
  );
}