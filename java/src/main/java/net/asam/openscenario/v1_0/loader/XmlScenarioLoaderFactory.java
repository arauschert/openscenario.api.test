/*
 * Copyright 2020 RA Consulting
 *
 * RA Consulting GmbH licenses this file under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except
 * in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package net.asam.openscenario.v1_0.loader;

import net.asam.openscenario.loader.IResourceLocator;
import net.asam.openscenario.loader.IScenarioLoader;
import net.asam.openscenario.loader.IScenarioLoaderFactory;

/**
 * Factory for a XML loader
 *
 * @author Andreas Hege - RA Consulting
 */
public class XmlScenarioLoaderFactory implements IScenarioLoaderFactory {

  private String filename;

  /**
   * Constructor
   *
   * @param filename for the created loader
   */
  public XmlScenarioLoaderFactory(String filename) {
    super();
    this.filename = filename;
  }

  @Override
  public IScenarioLoader createLoader(IResourceLocator resourceLocator) {
    return new XmlScenarioLoader(filename, resourceLocator);
  }
}
