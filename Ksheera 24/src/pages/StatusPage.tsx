import React, { useState, useEffect } from 'react';
import { Battery, Thermometer, Gauge, Anchor } from 'lucide-react';
import type { TelemetryData } from '../types';

function StatCard({ title, value, unit, icon: Icon }: {
  title: string;
  value: number;
  unit: string;
  icon: React.ElementType;
}) {
  return (
    <div className="bg-white rounded-lg shadow p-6">
      <div className="flex items-center justify-between">
        <div>
          <p className="text-sm font-medium text-gray-600">{title}</p>
          <p className="mt-2 text-3xl font-semibold text-gray-900">
            {value} {unit}
          </p>
        </div>
        <Icon className="h-8 w-8 text-blue-600" />
      </div>
    </div>
  );
}

export default function StatusPage() {
  const [telemetry, setTelemetry] = useState<TelemetryData>({
    battery: 85,
    temperature: 25,
    pressure: 2.5,
    depth: 15,
    timestamp: Date.now(),
  });

  useEffect(() => {
    const interval = setInterval(() => {
      setTelemetry(prev => ({
        battery: prev.battery + (Math.random() - 0.5) * 2,
        temperature: prev.temperature + (Math.random() - 0.5),
        pressure: prev.pressure + (Math.random() - 0.5) * 0.1,
        depth: prev.depth + (Math.random() - 0.5) * 0.5,
        timestamp: Date.now(),
      }));
    }, 1000);

    return () => clearInterval(interval);
  }, []);

  return (
    <div className="space-y-6">
      <h2 className="text-2xl font-bold text-gray-900">System Status</h2>
      <div className="grid grid-cols-1 gap-6 sm:grid-cols-2 lg:grid-cols-4">
        <StatCard
          title="Battery Level"
          value={Math.round(telemetry.battery)}
          unit="%"
          icon={Battery}
        />
        <StatCard
          title="Temperature"
          value={telemetry.temperature.toFixed(1)}
          unit="°C"
          icon={Thermometer}
        />
        <StatCard
          title="Pressure"
          value={telemetry.pressure.toFixed(2)}
          unit="bar"
          icon={Gauge}
        />
        <StatCard
          title="Depth"
          value={telemetry.depth.toFixed(1)}
          unit="m"
          icon={Anchor}
        />
      </div>
    </div>
  );
}