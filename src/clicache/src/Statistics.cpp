/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */



//#include "geode_includes.hpp"
#include "Statistics.hpp"
#include "StatisticDescriptor.hpp"
#include "StatisticsType.hpp"

#include "impl/ManagedString.hpp"
#include "ExceptionTypes.hpp"
#include "impl/SafeConvert.hpp"


namespace Apache
{
  namespace Geode
  {
    namespace Client
    {

      void Statistics::Close()
      {
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
          NativePtr->close();
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */ 
      }

      System::Int32 Statistics::NameToId(String^ name)
      {
        ManagedString mg_name( name );
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
          return NativePtr->nameToId(mg_name.CharPtr);
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */ 
      }

      StatisticDescriptor^ Statistics::NameToDescriptor(String^ name)
      {
        ManagedString mg_name( name );
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
          return StatisticDescriptor::Create(NativePtr->nameToDescriptor(mg_name.CharPtr));
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */ 
      }

      System::Int64 Statistics::UniqueId::get( )
      {
        return NativePtr->getUniqueId();
      }

      StatisticsType^ Statistics::Type::get( )
      { 
        return StatisticsType::Create(NativePtr->getType());
      }

      String^ Statistics::TextId::get()
      {
        return ManagedString::Get(NativePtr->getTextId());
      }

      System::Int64 Statistics::NumericId::get()
      {
        return NativePtr->getNumericId();
      }
      bool Statistics::IsAtomic::get()
      {
        return NativePtr->isAtomic();
      }
      bool Statistics::IsShared::get()
      {
        return NativePtr->isShared();
      }
      bool Statistics::IsClosed::get()
      {
        return NativePtr->isClosed();
      }
      
      void Statistics::SetInt(System::Int32 id, System::Int32 value)
      {
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
          NativePtr->setInt(id, value);
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */ 
      } 

      void Statistics::SetInt(String^ name, System::Int32 value)
      {
        ManagedString mg_name( name );
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
          NativePtr->setInt((char*)mg_name.CharPtr, value);
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */ 
      }

      void Statistics::SetInt(StatisticDescriptor^ descriptor, System::Int32 value)
      {
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
          NativePtr->setInt(GetNativePtr<apache::geode::statistics::StatisticDescriptor>(descriptor),value);
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */ 
      }

      void Statistics::SetLong(System::Int32 id, System::Int64 value)
      {
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
          NativePtr->setLong(id, value);
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */ 
      }

      void Statistics::SetLong(StatisticDescriptor^ descriptor, System::Int64 value)
      {
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
          NativePtr->setLong(GetNativePtr<apache::geode::statistics::StatisticDescriptor>(descriptor),value);
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */ 
      }

      void Statistics::SetLong(String^ name, System::Int64 value)
      {
        ManagedString mg_name( name );
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
          NativePtr->setLong((char*)mg_name.CharPtr, value);
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */ 
      }

      void Statistics::SetDouble(System::Int32 id, double value)
      {
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
          NativePtr->setDouble(id, value);
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */
      }

      void Statistics::SetDouble(String^ name, double value)
      {
        ManagedString mg_name( name );
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
          NativePtr->setDouble((char*)mg_name.CharPtr, value);
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */
      }

      void Statistics::SetDouble(StatisticDescriptor^ descriptor, double value)
      {
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
            NativePtr->setDouble(GetNativePtr<apache::geode::statistics::StatisticDescriptor>(descriptor), value);
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */
      }

      System::Int32 Statistics::GetInt(System::Int32 id)
      {
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
          return NativePtr->getInt(id);
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */
      }

      System::Int32 Statistics::GetInt(StatisticDescriptor^ descriptor)
      {
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
          return NativePtr->getInt(GetNativePtr<apache::geode::statistics::StatisticDescriptor>(descriptor));
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */
      }

      System::Int32 Statistics::GetInt(String^ name)
      {
        ManagedString mg_name( name );
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
          return NativePtr->getInt((char*)mg_name.CharPtr);
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */
      }

      System::Int64 Statistics::GetLong(System::Int32 id)
      {
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
           return NativePtr->getLong(id);
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */
      }
       System::Int64 Statistics::GetLong(StatisticDescriptor^ descriptor)
       {
          _GF_MG_EXCEPTION_TRY2/* due to auto replace */
            return NativePtr->getLong(GetNativePtr<apache::geode::statistics::StatisticDescriptor>(descriptor));
          _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */
       }

      System::Int64 Statistics::GetLong(String^ name)
      {
        ManagedString mg_name( name );
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
         return NativePtr->getLong((char*)mg_name.CharPtr);
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */
      }

      double Statistics::GetDouble(System::Int32 id)
      {
         _GF_MG_EXCEPTION_TRY2/* due to auto replace */
           return NativePtr->getDouble(id);
         _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */
      }

      double Statistics::GetDouble(StatisticDescriptor^ descriptor)
      {
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
           return NativePtr->getDouble(GetNativePtr<apache::geode::statistics::StatisticDescriptor>(descriptor));
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */
      }

      double Statistics::GetDouble(String^ name)
      {
        ManagedString mg_name( name );
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
          return NativePtr->getDouble((char*)mg_name.CharPtr);
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */
      }

      System::Int64 Statistics::GetRawBits(StatisticDescriptor^ descriptor)
      {
         _GF_MG_EXCEPTION_TRY2/* due to auto replace */
           return NativePtr->getRawBits(GetNativePtr<apache::geode::statistics::StatisticDescriptor>(descriptor));
         _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */
      }

      System::Int32 Statistics::IncInt(System::Int32 id, System::Int32 delta)
      {
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
          return NativePtr->incInt(id,delta);
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */
      }

      System::Int32 Statistics::IncInt(StatisticDescriptor^ descriptor, System::Int32 delta)
      {
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
          return NativePtr->incInt(GetNativePtr<apache::geode::statistics::StatisticDescriptor>(descriptor),delta);
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */
      }

      System::Int32 Statistics::IncInt(String^ name, System::Int32 delta)
      {
         ManagedString mg_name( name );
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
          return NativePtr->incInt((char*)mg_name.CharPtr,delta);
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */
      }

      System::Int64 Statistics::IncLong(System::Int32 id, System::Int64 delta)
      {
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
          return NativePtr->incLong(id,delta);
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */
      }

      System::Int64 Statistics::IncLong(StatisticDescriptor^ descriptor, System::Int64 delta)
      {
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
          return NativePtr->incLong(GetNativePtr<apache::geode::statistics::StatisticDescriptor>(descriptor),delta);
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */
      }

      System::Int64 Statistics::IncLong(String^ name, System::Int64 delta)
      {
         ManagedString mg_name( name );
         _GF_MG_EXCEPTION_TRY2/* due to auto replace */
           return NativePtr->incLong((char*)mg_name.CharPtr,delta);
         _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */
      }

      double Statistics::IncDouble(System::Int32 id, double delta)
      {
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
          return NativePtr->incDouble(id,delta);
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */
      }

      double Statistics::IncDouble(StatisticDescriptor^ descriptor, double delta)
      {
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
          return NativePtr->incDouble(GetNativePtr<apache::geode::statistics::StatisticDescriptor>(descriptor),delta);
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */
      }

      double Statistics::IncDouble(String^ name, double delta)
      {
        ManagedString mg_name( name );
        _GF_MG_EXCEPTION_TRY2/* due to auto replace */
          return NativePtr->incDouble((char*)mg_name.CharPtr,delta);
        _GF_MG_EXCEPTION_CATCH_ALL2/* due to auto replace */
    }  // namespace Client
  }  // namespace Geode
}  // namespace Apache
 } //namespace 

