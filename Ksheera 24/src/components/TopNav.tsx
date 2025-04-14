import React from 'react';
import { Anchor } from 'lucide-react';
import { useSystemStatus } from '../hooks/useSystemStatus';

export default function TopNav() {
  const { isOnline } = useSystemStatus();

  return (
    <header className="bg-white border-b border-gray-200">
      <div className="px-4 sm:px-6 lg:px-8">
        <div className="flex h-16 items-center justify-between">
          <div className="flex items-center">
            <Anchor className="h-8 w-8 text-blue-600" />
            <h1 className="ml-2 text-xl font-semibold text-gray-900">Ksheera AUV</h1>
          </div>
          <div className="flex items-center">
            <div className="flex items-center space-x-2">
              <div className={`h-3 w-3 rounded-full ${isOnline ? 'bg-green-500' : 'bg-red-500'}`} />
              <span className="text-sm text-gray-600">{isOnline ? 'Online' : 'Offline'}</span>
            </div>
          </div>
        </div>
      </div>
    </header>
  );
}