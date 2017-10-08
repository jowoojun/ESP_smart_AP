import React, {PureComponent} from 'react';


export default class Refuse extends PureComponent{

    render(){

        return(

            <div id="block_setting" className="col-md-8 well tabcontent current">
                <h1 className="page-header">
                    <small>차단 페이지 설정</small>
                </h1>
                <div className="onoffswitch">
                    <input type="checkbox" name="onoffswitch" className="onoffswitch-checkbox" id="myonoffswitch" checked />
                    <label className="onoffswitch-label" htmlFor="myonoffswitch">
                        <span className="onoffswitch-inner"></span>
                        <span className="onoffswitch-switch"></span>
                    </label>
                </div>
                <div>
                    <fieldset className="field block">
                        <legend><h4>차단페이지</h4></legend>
                        <select size="10" id="block_page" multiple>
                            <option id="option1_1" draggable="true">facebook</option>
                            <option id="option1_2" draggable="true">instagram</option>
                            <option id="option1_3" draggable="true">twitter</option>
                        </select>
                    </fieldset>
                    <div id="move_button">
                        <button className="btn btn-default" id="move_to_allow">▶</button><br />
                        <button className="btn btn-default" id="move_to_drop">◀</button>
                    </div>

                    <fieldset className="field">
                        <legend><h4>페이지리스트</h4></legend>
                        <select size="10" id="block_list" multiple></select>
                    </fieldset>

                    <div className="col-md-12">
                        <input type="submit" className="btn btn-default save_config" value="적용" />
                    </div>
                </div>
                </div>
        );
    }
}
