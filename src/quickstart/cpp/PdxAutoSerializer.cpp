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

/*
 * The PoolRemoteQuery QuickStart Example.
 * This examples creates pool using locator.
 * This example takes the following steps:
 *
 * 1. Create a Geode Cache.
 * 2. Get the example Region from the Pool.
 * 3. Populate some Pdx Type query objects on the Region.
 * 4. Get the pool, get the Query Service from Cache. Pool is define in
 * clientPdxRemoteQuery.xml. Pool has locator to get the server. Apart from that
 * pool is bind to server group "ServerGroup1".
 * 5. Execute a query that returns a Result Set.
 * 6. Execute a query that returns a Struct Set.
 * 7. Execute the region shortcut/convenience query methods.
 * 8. Close the Cache.
 *
 */

// Include the Geode library.
#include <geode/GeodeCppCache.hpp>

// Include our Query objects, viz. PortfolioPdx and PositionPdx.
#include "queryobjects/PortfolioPdxAuto.hpp"
#include "queryobjects/PositionPdxAuto.hpp"

// Use the "geode" namespace.
using namespace apache::geode::client;

// Use the "testobject" namespace for the query objects.
using namespace testobject;

// The PdxRemoteQuery QuickStart example.
int main(int argc, char** argv) {
  try {
    CacheFactoryPtr cacheFactory = CacheFactory::createCacheFactory();

    // Create a Geode Cache with the "clientPdxRemoteQuery.xml" Cache XML
    // file.
    // CachePtr cachePtr = cacheFactory->set("cache-xml-file",
    // "XMLs/clientPdxAutoSerializer.xml")->create();
    CachePtr cachePtr =
        cacheFactory->set("cache-xml-file", "XMLs/clientPdxAutoSerializer.xml")
            ->create();

    LOGINFO("Created the Geode Cache");

    // Get the example Region from the Cache which is declared in the Cache XML
    // file.
    RegionPtr regionPtr = cachePtr->getRegion("Portfolios");

    LOGINFO("Obtained the Region from the Cache");

    // Register our Serializable/Cacheable Query objects, viz. PortfolioPdx and
    // PositionPdx.
    Serializable::registerPdxType(PortfolioPdxAuto::createDeserializable);
    Serializable::registerPdxType(PositionPdxAuto::createDeserializable);

    LOGINFO("Registered PDX Type Query Objects");

    // Populate the Region with some Pdx Type objects, i.e PortfolioPdx objects.
    PortfolioPdxPtr port1Ptr(new PortfolioPdxAuto(1 /*ID*/, 10 /*size*/));
    PortfolioPdxPtr port2Ptr(new PortfolioPdxAuto(2 /*ID*/, 20 /*size*/));
    PortfolioPdxPtr port3Ptr(new PortfolioPdxAuto(3 /*ID*/, 30 /*size*/));
    regionPtr->put("Key1", port1Ptr);
    regionPtr->put("Key2", port2Ptr);
    regionPtr->put("Key3", port3Ptr);

    LOGINFO("Populated some PortfolioPdx Objects");

    // Get the QueryService from the Cache.
    QueryServicePtr qrySvcPtr = cachePtr->getQueryService("examplePool");

    LOGINFO("Got the QueryService from the Cache");

    PortfolioPdxPtr port4Ptr = regionPtr->get("Key1");

    // Execute a Query which returns a ResultSet.
    QueryPtr qryPtr = qrySvcPtr->newQuery("SELECT DISTINCT * FROM /Portfolios");
    SelectResultsPtr resultsPtr = qryPtr->execute();

    LOGINFO("ResultSet Query returned %d rows", resultsPtr->size());

    // Execute a Query which returns a StructSet.
    qryPtr = qrySvcPtr->newQuery(
        "SELECT DISTINCT id, status FROM /Portfolios WHERE id > 1");
    resultsPtr = qryPtr->execute();

    LOGINFO("StructSet Query returned %d rows", resultsPtr->size());

    // Iterate through the rows of the query result.
    int rowCount = 0;
    SelectResultsIterator iter = resultsPtr->getIterator();
    while (iter.hasNext()) {
      rowCount++;
      Struct* psi = dynamic_cast<Struct*>(iter.next().ptr());
      LOGINFO("Row %d Column 1 is named %s, value is %s", rowCount,
              psi->getFieldName(0), (*psi)[0]->toString()->asChar());
      LOGINFO("Row %d Column 2 is named %s, value is %S", rowCount,
              psi->getFieldName(1), (*psi)[1]->toString()->asWChar());
    }

    // Execute a Region Shortcut Query (convenience method).
    resultsPtr = regionPtr->query("id = 2");

    LOGINFO("Region Query returned %d rows", resultsPtr->size());

    // Execute the Region selectValue() API.
    SerializablePtr resultPtr = regionPtr->selectValue("id = 3");
    PortfolioPdxPtr portPtr = dynCast<PortfolioPdxPtr>(resultPtr);

    LOGINFO("Region selectValue() returned an item:\n %s",
            portPtr->toString()->asChar());

    // Execute the Region existsValue() API.
    bool existsValue = regionPtr->existsValue("id = 4");

    LOGINFO("Region existsValue() returned %s", existsValue ? "true" : "false");

    // Close the Geode Cache.
    cachePtr->close();

    LOGINFO("Closed the Geode Cache");

    return 0;
  }
  // An exception should not occur
  catch (const Exception& geodeExcp) {
    LOGERROR("PdxAutoSerializer Geode Exception: %s", geodeExcp.getMessage());

    return 1;
  }
}
