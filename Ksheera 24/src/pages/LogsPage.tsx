import React from 'react';

function LogsPage() {
  return (
    <div className="p-6">
      <h1 className="text-2xl font-bold mb-6">System Logs</h1>
      <div className="bg-gray-800 text-gray-100 p-4 rounded-lg font-mono text-sm overflow-auto max-h-[calc(100vh-12rem)]">
        <pre>
          {/* Placeholder for actual log content */}
          [2024-01-20 02:55:01] System initialized
          [2024-01-20 02:55:02] Connection established
          [2024-01-20 02:55:03] Sensors online
        </pre>
      </div>
    </div>
  );
}

export default LogsPage;