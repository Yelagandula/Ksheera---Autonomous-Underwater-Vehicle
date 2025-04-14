export interface TelemetryData {
  battery: number;
  temperature: number;
  pressure: number;
  depth: number;
  timestamp: number;
}

export interface LogEntry {
  id: string;
  timestamp: Date;
  message: string;
  severity: 'info' | 'warning' | 'error';
}

export interface SystemStatus {
  isOnline: boolean;
  mode: 'auto' | 'manual';
  targetDepth: number;
}