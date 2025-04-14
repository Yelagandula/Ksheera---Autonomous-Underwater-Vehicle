import React, { useEffect, useState } from "react";
import {
  LineChart, Line, XAxis, YAxis, CartesianGrid, Tooltip, ResponsiveContainer,
} from 'recharts';

const generateFakeTelemetry = () => ({
  timestamp: new Date().toLocaleTimeString(),
  depth: +(Math.random() * 100).toFixed(2),
  temperature: +(20 + Math.random() * 5).toFixed(2),
  battery: +(50 + Math.random() * 50).toFixed(2),
  pressure: +(1 + Math.random()).toFixed(2),
});

export default function Telemetry() {
  const [data, setData] = useState([]);

  useEffect(() => {
    const interval = setInterval(() => {
      setData(prev => {
        const newData = [...prev, generateFakeTelemetry()];
        return newData.length > 20 ? newData.slice(-20) : newData;
      });
    }, 1000);
    return () => clearInterval(interval);
  }, []);

  const latest = data[data.length - 1] || {};

  return (
    <div className="space-y-6 p-4">
      <h2 className="text-2xl font-bold">System Telemetry</h2>

      {/* Stat Cards */}
      <div className="grid grid-cols-2 md:grid-cols-4 gap-4">
        <div className="bg-white p-4 rounded shadow">
          <p className="text-sm text-gray-500">Battery</p>
          <p className="text-xl font-semibold">{latest.battery ?? "--"}%</p>
        </div>
        <div className="bg-white p-4 rounded shadow">
          <p className="text-sm text-gray-500">Temperature</p>
          <p className="text-xl font-semibold">{latest.temperature ?? "--"}°C</p>
        </div>
        <div className="bg-white p-4 rounded shadow">
          <p className="text-sm text-gray-500">Pressure</p>
          <p className="text-xl font-semibold">{latest.pressure ?? "--"} bar</p>
        </div>
        <div className="bg-white p-4 rounded shadow">
          <p className="text-sm text-gray-500">Depth</p>
          <p className="text-xl font-semibold">{latest.depth ?? "--"} m</p>
        </div>
      </div>

      {/* Charts */}
      <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
        <div className="bg-white p-4 rounded shadow">
          <h3 className="font-medium mb-2">Depth Over Time</h3>
          <ResponsiveContainer width="100%" height={200}>
            <LineChart data={data}>
              <CartesianGrid strokeDasharray="3 3" />
              <XAxis dataKey="timestamp" />
              <YAxis />
              <Tooltip />
              <Line type="monotone" dataKey="depth" stroke="#3b82f6" />
            </LineChart>
          </ResponsiveContainer>
        </div>

        <div className="bg-white p-4 rounded shadow">
          <h3 className="font-medium mb-2">Temperature Over Time</h3>
          <ResponsiveContainer width="100%" height={200}>
            <LineChart data={data}>
              <CartesianGrid strokeDasharray="3 3" />
              <XAxis dataKey="timestamp" />
              <YAxis />
              <Tooltip />
              <Line type="monotone" dataKey="temperature" stroke="#ef4444" />
            </LineChart>
          </ResponsiveContainer>
        </div>
      </div>
    </div>
  );
}
