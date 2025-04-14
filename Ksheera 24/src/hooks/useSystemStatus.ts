import { useState, useEffect } from 'react';
import type { SystemStatus } from '../types';

export function useSystemStatus() {
  const [status, setStatus] = useState<SystemStatus>({
    isOnline: true,
    mode: 'auto',
    targetDepth: 0,
  });

  useEffect(() => {
    // Simulate random connection drops
    const interval = setInterval(() => {
      setStatus(prev => ({
        ...prev,
        isOnline: Math.random() > 0.1,
      }));
    }, 5000);

    return () => clearInterval(interval);
  }, []);

  const setMode = (mode: 'auto' | 'manual') => {
    setStatus(prev => ({ ...prev, mode }));
  };

  const setTargetDepth = (depth: number) => {
    setStatus(prev => ({ ...prev, targetDepth: depth }));
  };

  return {
    ...status,
    setMode,
    setTargetDepth,
  };
}